import sys
import subprocess
import glob
import os

from lofarpipe.support.lofarnode import LOFARnodeTCP

class thumbnail_combine(LOFARnodeTCP):
    def run(self, file_pattern, input_dir, output_file, clobber):
        if not os.path.exists(input_dir):
            self.logger.error("Input directory (%s) not found" % input_dir)
            return 1

        self.logger.info("Processing %s" % input_dir)

        if os.path.exists(output_file):
            if clobber:
                self.logger.warn(
                    "Deleting previous version of results: %s" % output_file
                )
                os.unlink(output_file)
            else:
                self.logger.error(
                    "Refusing to overwrite existing file %s" % output_file
                )
                return 1

        input_files = glob.glob(os.path.join(input_dir, file_pattern))

        try:
            # Run "montage" command
            subprocess.check_call(['/usr/bin/montage'] + input_files + [output_file])
        except Exception, e:
            self.logger.error(str(e))
            return 1

        if not os.path.exists(output_file):
            self.logger.error(
                "Output file %s not created by montage exectuable" % output_file
            )
            return 1

        return 0

if __name__ == "__main__":
    jobid, jobhost, jobport = sys.argv[1:4]
    sys.exit(thumbnail_combine(jobid, jobhost, jobport).run_with_stored_arguments())
