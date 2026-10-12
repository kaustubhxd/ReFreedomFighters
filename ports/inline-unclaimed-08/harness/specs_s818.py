"""specs_s818.py - unclaimed-08 batch 818 (residue 7, ragdoll): CRigidBody::ProjectSphereOutFromPlane, stdcall, ten stack
arguments (ret 0x28). Arguments: A, B, C, D, K, F, G, H, I (pointers to float[3], heap) and J (float).

The helpers 0x451890, 0x441940, 0x43e8e0 and 0x443ef0 run the original code (x87), so no stubs are needed. The vectors are
random floats in [-4, 4] so that the dot test is true about half the time and the 9.0 threshold is crossed both ways.
J is random in [-2, 2]."""
from pilot import S, F
import struct


def _vec(c, lo=-4.0, hi=4.0):
    a = c.emu.alloc(12, 4)
    c.emu.wbytes(a, b''.join(struct.pack('<f', c.rng.uniform(lo, hi)) for _ in range(3)))
    return a


def _proj(c):
    args = [_vec(c) for _ in range(9)]           # A, B, C, D, K, F, G, H, I
    if c.rng.random() < 0.1:                      # D = 0: dot is exactly 0, the 0 > dot test is false
        c.emu.wbytes(args[3], b'\0' * 12)
    args.append(F(c.rng.uniform(-2.0, 2.0)))     # J
    return args


S(0x5403f0, 'CRigidBody::ProjectSphereOutFromPlane (unknown)', 'stdcall', None, ret=None, gen=_proj,
  note='unclaimed-08 batch 18 (residue 7, ragdoll); helpers 0x451890/0x441940/0x43e8e0/0x443ef0 original (x87)')
