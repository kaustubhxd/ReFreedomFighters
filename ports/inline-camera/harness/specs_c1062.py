"""specs_c1062.py - camera batch 1062: ZFFCameraClass::CopyDataBlock (0x5b22e0). The camera part is ZCAMERA::CopyDataBlock
(0x445800, original code here), so the same camera and data-block setup as specs_c1061 is used."""
from pilot import S
import specs_c1061


S(0x5b22e0, 'ZFFCameraClass::CopyDataBlock', 'thiscall', gen=specs_c1061._cdb)
